library(readxl)
library(dplyr)
library(tidyr)
library(ggplot2)
# Lê os ficheiros do excel
owid_covid_data <- read_excel("C:/Users/pedro/Desktop/ANADI/owid-covid-data.xlsx")
view(owid_covid_data)
# Agrupa por continente
por_continente <- owid_covid_data %>% 
  drop_na(continent, date, total_cases_per_million) %>% 
  group_by(date, continent) %>% 
  summarize(total_cases_per_million = sum(total_cases_per_million)) %>% 
por_continente$date <- as.Date(por_continente$date, format="%Y-%m-%d")
# Desenha o gráfico
por_continente %>% 
  ggplot(aes(x=date, y=total_cases_per_million, group=continent, colour=continent)) +
  scale_y_continuous(trans = "log2") +
  geom_line() +
  ggtitle("Total de infetados por milhão de habitantes\nao longo do período de tempo, por continente.") +
  labs(x="Data", y="Total de infetados por milhão", colour="Continente")
