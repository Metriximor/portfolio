library(readxl)
library(dplyr)
library(tidyr)
library(ggplot2)
library(ggpubr)

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

ggscatter(data_eu_10M, 
          x = "population_density",
          y = "max_reproduction_rate",
          color="location")
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

#4b Verifique se as condições de: Homocedasticidade, Autocorrelação nula e de Multicolinearidade são
#     satisfeitas. 
