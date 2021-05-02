library(readxl)
library(dplyr)
library(tidyr)
library(ggplot2)
library(ggpubr)
library(car)

data <- read_excel("C:/Users/pedro/Desktop/ANADI/owid-covid-data.xlsx") #Lê o ficheiro excel

#1b Gráfico do total de infetados por milhão de habitantes, ao longo do período de tempo, por continente. 
data %>% 
  drop_na(continent, date, total_cases_per_million) %>% # Apaga os campos vazios
  group_by(date, continent) %>% # Agrupa por data e continente
  summarize(total_cases_per_million = sum(total_cases_per_million)) %>% # Soma todos os casos por data e continente
  mutate(date = as.Date(date, format="%Y-%m-%d")) %>% # Converte a data num formato correto
  ggplot(aes(x=date, y=total_cases_per_million, group=continent, colour=continent)) + #Faz o plot do gráfico
    scale_y_continuous(trans = "log2") + # Define a escala logaritmica
    geom_line() + 
    ggtitle("Total de novos casos infetados por milhão de habitantes\nao longo do período de tempo, por continente.") +
    labs(x="Data", y="Total de infetados por milhão", colour="Continente")

#1e Indique qual o país europeu que teve o maior número de infetados, por milhão de habitantes, num só dia. 
data %>% 
  filter(continent == "Europe") %>%
  drop_na(continent,new_cases_per_million,date) %>% 
  slice_max(new_cases_per_million) %>% 
  View()

#2a Considerando apenas os dados relativos, a 30 dias, da amostra pseudoaleatória (usando o valor 118
#     no parâmetro da função set.seed()) que obteve, verifique se a média da taxa transmissibilidade no
#     Reino Unido é superior à média da taxa de transmissibilidade em Portugal. 
set.seed(118)
data %>% 
  filter(location == "United Kingdom") %>% #Filtra por casos somente do Reino Unido
  filter(date >= "2020-04-01" & date <= "2021-02-27") %>% #Filtra por casos só dentro das datas pretendidas
  drop_na(reproduction_rate) %>% #Remove todos os campos vazios na coluna da transmissão
  slice_sample(n = 30) %>% #Seleciona 30 linhas aleatórias
  summarise(mean(reproduction_rate)) #Calcula a média da taxa de reprodução
# Resultado: 1.02

set.seed(118)
data %>% 
  filter(location == "Portugal") %>% 
  filter(date >= "2020-04-01" & date <= "2021-02-27") %>% 
  drop_na(reproduction_rate) %>% 
  slice_sample(n= 30) %>% 
  summarise(mean(reproduction_rate))
# Resultado: 1.08
# Conclusão: A média da taxa de transmissibilidade de Portugal é superior á do Reino Unido

#3a Averigue se existe correlação, em 2021, entre o valor máximo da taxa diária de transmissibilidade
#     e a densidade populacional de todos os países da Europa com mais de 10 milhões de habitantes
data_eu_10M <- data %>% 
  filter(continent == "Europe" & population > 10000000 & substring(date, 1, 4) == "2021") %>% 
  drop_na(reproduction_rate, population_density) %>% 
  group_by(location, population_density) %>% 
  summarise(max_reproduction_rate = max(reproduction_rate))

# Testes
# 1. Variáveis são continuas? Sim
# 2. Dados estão emparelhados? Sim
# 3. Observações sao independentes? Sim, a observação dos dados no pais X não influenciou os dados do pais Y
# 4. Variáveis seguem (aproximadamente) uma distribuição normal? (ver abaixo)
# 5. Há outliers? Nenhum que se destaque

ggscatter(data_eu_10M, 
          x = "population_density",
          y = "max_reproduction_rate",
          label="location",
          add = "reg.line", conf.int = TRUE, 
          cor.coef = TRUE, cor.method = "pearson")

shapiro.test(data_eu_10M$max_reproduction_rate) #p <- 0.9177
shapiro.test(data_eu_10M$population_density) #p <- 0.02673

# Taxa de transmissão máxima possui um p bastante elevado, sugerindo uma distribuição normal
# Densidade populacional possui um p inferior a 0.05, sugerindo que a distribuição não seja normal

ggqqplot(data_eu_10M$max_reproduction_rate, ylab = "Máximo taxa diária de transmissibilidade")
ggqqplot(data_eu_10M$population_density, ylab = "Densidade Populacional")

# Como se pode ver pelos qqplots, a densidade populacional continua a ser relativamente considerada
#   como uma distribuição normal

cor.test(data_eu_10M$max_reproduction_rate, data_eu_10M$population_density,
         method = "pearson")

# Resultados do teste: com p de 0.5306 pode-se concluir que não existe correlação entre 
#   o valor máximo da taxa diária de transmissibilidade e a densidade populacional
#   de todos os países da Europa com mais de 10 milhões de habitantes

# Spearman - não pode ser porque não há uma relação monotónica
# Kendall - não pode ser porque não há uma relação monotónica

#4a

def <- data %>%
  filter(location == "Portugal") %>% #Filtra casos por Portugal
  filter(date >= "2020-04-01" & date <= "2021-02-27") %>% #Filtra os dados entra as datas pretendidas
  summarise(reproduction_rate,new_cases_per_million,new_deaths_per_million,date,stringency_index)

#remover dados necessários
media_stringency_por_mes <- def %>%
  drop_na(stringency_index) %>% # remove os campos vazios desta coluna
  group_by(substr(date,6,7)) %>% # agrupa os dados pelo mês da data
  summarise(med= mean(stringency_index)) # Efetua a média por mês
stringency <- unlist(media_stringency_por_mes$med)


media_casos_diarios<- def %>%
  drop_na(new_cases_per_million) %>% # remove os campos vazios desta coluna
  group_by(substr(date,6,7)) %>% # agrupa os dados pelo mês da data
  summarise(med = mean(new_cases_per_million)) # Efetua a média por mês
novos_casos <- unlist(media_casos_diarios$med)

media_por_mes_transm <- def %>%
  drop_na(reproduction_rate) %>% # remove os campos vazios desta coluna
  group_by(substr(date,6,7)) %>% # agrupa os dados pelo mês da data
  summarise(med = mean(reproduction_rate)) 
media_mensal_transm <- unlist(media_por_mes_transm$med)
#media mensal de transmissibilidade = 1.04033822091887


media_mortes_diarias <- def %>%
  drop_na(new_deaths_per_million) %>% # remove os campos vazios desta coluna
  group_by(substr(date,6,7)) %>% # agrupa os dados pelo mês da data
  summarise(med = mean(new_deaths_per_million)) 
mortes_diarias <- unlist(media_mortes_diarias$med)

X <- novos_casos + mortes_diarias +media_mensal_transm
model <- lm(stringency ~  X)
summary(model)

#4b Verifique se as condições de: Homocedasticidade, Autocorrelação nula e de Multicolinearidade são
#     satisfeitas. 

# Residuos seguem distribuição normal?
qqnorm (residuals(model), ylab =" Residuos ", xlab =" Quantis teóricos")
qqline (residuals(model))

shapiro.test(residuals(model))
# p = 0.4467 é superior a 0.01 logo a condição de normalidade é respeitada e podemos efetuar inferência estatistica

# Verificação de Homocedasticidade

plot(fitted(model),residuals(model),xlab="Valores ajustados",ylab="Residuos")
abline(h=0)
plot(X,residuals(model),xlab="X",yLab="Residuos")
abline(h=0)

var.test(residuals(model)[X>median(X)],residuals(model)[X<median(X)])
# Condição de homocedasticidade é verificada

# Verificação de autocorrelação nula
durbinWatsonTest(model)
# Valor p é igual a 0.836, logo pode-se rejeitar a hipótese nula e acreditar que os residuais estão correlacionados.
# Como o valor 

# Verificação de multicolinearidade
vif(model)
# VIF é superior a 3 para cada uma das colunas, logo confirma-se a existência de multicolinearidade
