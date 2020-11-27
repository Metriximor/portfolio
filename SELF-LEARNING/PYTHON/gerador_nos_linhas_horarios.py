# -*- coding: utf-8 -*-
import random
import string
import math
import time
import sys
import os

# PARA USAR ISTO CORRER: py gerador_nos_linhas.py (num nós desejados) (num linhas desejados)
# É recomendável ter um número equiparado de linhas e nós


def generate_no_name(name_length=3):
    return ''.join(random.choice(string.ascii_uppercase) for i in range(name_length))


def gen_true_false():
    return random.choice('tfffff')


def gen_rand_lat():
    return str(random.uniform(-7.645935, -8.101198))


def gen_rand_lon():
    return str(random.uniform(39.666869, 41.127933))


def generate_no(no_name):
    return "no('"+no_name.title()+"','"+no_name+"',"+gen_true_false()+","+gen_true_false()+","+gen_rand_lat()+","+gen_rand_lon()+")."


def pick_random(estacoes_list):
    return random.choice(estacoes_list)


def gen_lista_nos(stations, used, first, last, horarios):
    estacoes_list = ''
    num_estacoes = random.randint(0, min(10, len(stations)-2))
    num_horario = random.randint(1,5)
    for i in range(num_horario): # Cria os horários
        station_time = random.randint(25200,36000)
        horario = list()
        horario.append(station_time)
        horarios.append(horario)
    while len(used)-2 < num_estacoes:
        station = pick_random(stations)
        while station in used:
            station = pick_random(stations)
        used.add(station)
    for station in used:
        if(station == first or station == last):
            continue
        estacoes_list += "'"+station+"',"
        for horario in horarios: # Adiciona o horário das estações no meio
            station_time = horario[-1] + random.randint(300,600)
            horario.append(station_time)
    for horario in horarios: # Adiciona o horário da ultima paragem
        station_time = horario[-1] + random.randint(300,600)
        horario.append(station_time)
    return estacoes_list


def generate_linha(stations, num_linha):
    used_stations = set()  # Para não utilizar o mesmo nó duas vezes
    first_station = pick_random(stations)
    used_stations.add(first_station)
    last_station = pick_random(stations)
    while last_station in used_stations:
        last_station = pick_random(stations)
    used_stations.add(last_station)
    horarios=list()
    return_str="linha('"+first_station.title()+"_"+last_station.title()+"',"+str(num_linha)+",['"+first_station+"',"+gen_lista_nos(
        stations, used_stations, first_station, last_station, horarios)+"'"+last_station+"']).\n"
    for horario in horarios:
        return_str+="horario("+str(num_linha)+",["
        for hora in horario:
            return_str+= str(hora)+","
        return_str = return_str[:-1]
        return_str+="]).\n"
    return return_str

if len(sys.argv) <= 2:
    print("É necessário indicar o número de nós e o número de linhas desejados")
    sys.exit(1)

n_max = int(sys.argv[1])

if n_max <= 1:
    print("É necessário indicar um número de nós superior a 1")
    sys.exit(1)

l_max = int(sys.argv[2])

if l_max <= 1:
    print("É necessário indicar um número de linhas superior a 1")
    sys.exit(1)

no_name_length = int(math.ceil(math.log(n_max, len(string.ascii_uppercase))))
no_name_set = set()

start_time = time.time()

print("A gerar os nós")
while len(no_name_set) < n_max:
    no_name_set.add(generate_no_name(no_name_length))
print("Nós gerados")

file_name = str(n_max)+"nos_"+str(l_max)+"linhas_horarios.pl"
if os.path.exists(file_name):
    os.remove(file_name)

file = open(file_name, "a")
file.write("% Nós\n")

for no_name in no_name_set:
    file.write(generate_no(no_name)+"\n")

no_name_list = list(no_name_set)
file.write("\n% Linhas\n")
file.write(":- discontiguous linha/3.\n")
file.write(":- discontiguous horario/3.\n")
print("A gerar as linhas")
horarios = set()
for i in range(1, l_max+1):
    file.write(generate_linha(no_name_list, i)+"\n")
print("Linhas geradas")

print("Gerou "+str(n_max)+" nós e "+str(l_max) +
      " linhas em "+str(time.time()-start_time)+" segundos")

file.close()
sys.exit(0)
