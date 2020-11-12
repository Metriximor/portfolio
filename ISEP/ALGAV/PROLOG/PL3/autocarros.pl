% nome do nó, abreviatura do nó, indicação se é
% ponto de rendição (t para verdade, f para falso), indicação se é estação
% de recolha (t para verdade, f para falso), latitude, longitude

no('Aguiar de Sousa', 'AGUIA', f, f, -8.4464785432391, 41.1293363229325).
no('Baltar', 'BALTR', f, f, -8.38716802227697, 41.1937898023744).
no('Besteiros', 'BESTR', f, f, -8.34043029659082, 41.217018845589).
no('Cete', 'CETE', f, f, -8.35164059584564, 41.183243425797).
no('Cristelo', 'CRIST', t, f, -8.34639896125324, 41.2207801252676).
no('Duas Igrejas', 'DIGRJ', f, f, -8.35481024956726, 41.2278665802794).
no('Estação (Lordelo)', 'ESTLO', f, t, -8.4227924957086, 41.2521157104055).
no('Estação (Paredes)', 'ESTPA', f, t, -8.33448520831829, 41.2082119860192).
no('Gandra', 'GAND', f, f, -8.43958765792976, 41.1956579348384).
no('Lordelo', 'LORDL', t, f, -8.42293614720057, 41.2452627470645).
no('Mouriz', 'MOURZ', f, f, -8.36577272258403, 41.1983610215263).
no('Parada de Todeia', 'PARAD', f, f, -8.37023578802149, 41.1765780321068).
no('Paredes', 'PARED', t, f, -8.33566951069481, 41.2062947118362).
no('Recarei', 'RECAR', f, f, -8.42215867462191, 41.1599363478137).
no('Sobrosa', 'SOBRO', t, f, -8.38118071581788, 41.2557331783506).
no('Vandama', 'VANDO', f, f, -8.34160692293342, 41.2328015719913).
no('Vila Cova de Carros', 'VCCAR', f, f, -8.35109395257277, 41.2090666564063).

linha('Paredes_Aguiar', 1, ['AGUIA','RECAR', 'PARAD', 'CETE', 'PARED'], 31, 15700).
linha('Paredes_Aguiar', 2, ['PARED', 'CETE','PARAD', 'RECAR', 'AGUIA'], 31, 15700).
linha('Paredes_Gandra', 3 , ['GAND', 'VANDO', 'BALTR', 'MOURZ', 'PARED'], 26, 13000).
linha('Paredes_Gandra', 4, ['PARED', 'MOURZ', 'BALTR', 'VANDO', 'GAND'], 26, 13000).
linha('Paredes_Lordelo', 5, ['LORDL','VANDO', 'BALTR', 'MOURZ', 'PARED'], 29, 14300).
linha('Paredes_Lordelo', 6, ['PARED','MOURZ', 'BALTR', 'VANDO', 'LORDL'], 29, 14300).
linha('Lordelo_Parada', 7, ['LORDL', 'DIGRJ', 'CRIST', 'VCCAR', 'BALTR', 'PARAD'], 22, 11000).
linha('Lordelo_Parada', 8, ['PARAD', 'BARTR', 'VCCAR', 'CRIST', 'DIGRJ', 'LORDL'], 22, 11000).
linha('Cristelo_Baltar', 9, ['CRIST', 'VCCAR', 'BALTR'], 8, 4000).
linha('Baltar_Cristelo', 10, ['BARTR', 'VCCAR', 'CRIST'], 8, 4000).
linha('Sobrosa_Cete', 12, ['SOBRO', 'CRIST', 'BESTR', 'VCCAR', 'MOURZ', 'CETE'], 23, 11500).
linha('Sobrosa_Cete', 13, ['CETE', 'MOURZ', 'VCCAR', 'BESTR', 'CRIST', 'SOBRO'], 23, 11500).
linha('Estação(Lordelo)_Lordelo',14,['ESTLO','LORDL'], 2,1500).
linha('Lordelo_Estação(Lordelo)',15,['LORDL','ESTLO'], 2,1500).
linha('Estação(Lordelo)_Sobrosa',16,['ESTLO','SOBRO'], 5,1500).
linha('Sobrosa_Estação(Lordelo)',17,['SOBRO','ESTLO'], 5,1800).
linha('Estação(Paredes)_Paredes',18,['ESTPA','PARED'], 2,1500).
linha('Paredes_Estação(Paredes)',19,['PARED','ESTPA'], 2,1500).

% Escreva um predicado Prolog gera_ligacoes/0 (0 significa que não
% tem argumentos) que seja capaz de gerar todas as ligações diretas
% entre pontos de rendição ou estações de recolha (no fundo onde
% podem mudar os motoristas/tripulações). As ligações diretas ocorrem
% quando há um autocarro que passa por esses dois pontos (rendição
% ou recolha). Notar que deve passar pelo primeiro ponto e só depois
% pelo segundo. O predicado gera_ligacoes/0 deverá fazer o assert das
% ligações através de termos liga/3, onde os dois primeiros argumentos
% são os dois pontos (rendição ou recolha) e o terceiro argumento é o
% nº da linha de autocarro. Por exemplo, para ir do ponto de rendição
% Paredes para o ponto de rendição Lordelo podemos usar o autocarro
% nº 6, sendo criado pelo assert o seguinte facto: 
% liga('PARED', 'LORDL', 6)

membro_ordem(A, L, O):-
    membro_ordem(A, L, O, 0).

membro_ordem(A, [A|_], O, O).

membro_ordem(A, [_|T], O, C):-
    C1 is C + 1,
    membro_ordem(A, T, O, C1).

is_ponto_troca(A):-
    no(_,A,t,_,_,_);
    no(_,A,_,t,_,_).

gera_ligacoes2():-
    no(_,A,_,_,_,_),
    is_ponto_troca(A),
    no(_,B,_,_,_,_),
    A \== B,
    is_ponto_troca(B),
    linha(_,L,H,_,_),
    membro_ordem(A, H, O1),
    membro_ordem(B, H, O2),
    O1 < O2,
    assertz(liga(A,B,L)),
    write("Ligacao: "),write(A),write(" para "),write(B),write(" na linha "),write(L),write("\n").

gera_ligacoes():-
    findall(_, gera_ligacoes2(), _).

% Escreva um predicado Prolog caminho/3 que seja capaz de gerar um
% caminho entre um ponto de rendição ou ponto de recolha para outro 
% ponto de rendição ou ponto de recolha e envolvendo o uso de uma
% ou mais linhas de autocarro. Notar que só podemos trocar de linha
% em pontos de rendição ou estações de recolha. Por exemplo, se
% perguntarmos quais os caminhos entre Estação de Paredes e Cristelo
% são gerados 2 caminhos possíveis

caminho(E,E,[],_).

caminho(S,E,[(S,S1,S2)|C],Exp):- %Exp está aqui para evitar loops infinitos
    not(member(S,Exp)),
    liga(S,S1,S2),
    caminho(S1,E,C,[S|Exp]).

caminho(S,E,[(S,S1,S2)|C]):-
    liga(S,S1,S2),
    caminho(S1,E,C,[S]).

% Escreva um predicado Prolog menor_ntrocas/3 que seja capaz de
% gerar o caminho entre um ponto de rendição ou ponto de recolha
% para outro ponto de rendição ou ponto de recolha envolvendo o uso
% do menor número de linhas, ou seja, minimizando o número de
% trocas de linhas. Por exemplo, se perguntarmos qual o caminho com
% menos trocas de linha entre Estação de Paredes e Cristelo é gerada a
% seguinte solução: 

tamanho_lista([],R,R).

tamanho_lista([_|T], Ta, R):-
    Tb is Ta + 1,
    tamanho_lista(T, Tb, R).

tamanho_lista([_|T], R):-
    tamanho_lista(T, 1, R).

lista_mais_pq([],R,_,R).

lista_mais_pq([H|T], A, T_L, L_P):-
    tamanho_lista(H, R),
    (R < T_L,
    lista_mais_pq(T, H, R, L_P));
    lista_mais_pq(T, A, T_L, L_P).

lista_mais_pq([H|T], L_P):-
    tamanho_lista(H, R),
    lista_mais_pq(T, H, R, L_P).

menor_ntrocas(S,E,C):-
    findall(L1, caminho(S,E,L1), L),
    lista_mais_pq(L, C).
