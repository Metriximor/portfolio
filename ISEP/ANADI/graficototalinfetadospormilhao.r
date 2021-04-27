library(readxl)
library(dplyr)
library(tidyr)
library(ggplot2)

data <- read_excel("C:/Users/pedro/Desktop/ANADI/owid-covid-data.xlsx") #Lê o ficheiro excel
#1b Gráfico do total de infetados por milhão de habitantes, ao longo do período de tempo, por continente. 
data %>% 
  drop_na(continent, date, new_cases_smoothed_per_million) %>% # Apaga os campos vazios
  group_by(date, continent) %>% # Agrupa por data e continente
  summarize(new_cases_smoothed_per_million = sum(new_cases_smoothed_per_million)) %>% # Soma todos os casos por data e continente
  mutate(date = as.Date(date, format="%Y-%m-%d")) %>% # Converte a data num formato correto
  ggplot(aes(x=date, y=new_cases_smoothed_per_million, group=continent, colour=continent)) + #Faz o plot do gráfico
    scale_y_continuous(trans = "log2") + # Define a escala logaritmica
    geom_line() + 
    ggtitle("Total de infetados por milhão de habitantes\nao longo do período de tempo, por continente.") +
    labs(x="Data", y="Total de infetados por milhão", colour="Continente")
#1e Indique qual o país europeu que teve o maior número de infetados, por milhão de habitantes, num só dia. 
data %>% 
  drop_na(continent,new_cases_per_million,date) %>% 
  filter(continent == "Europe") %>% 
  filter(max())
#2a 
#3a
#4b
