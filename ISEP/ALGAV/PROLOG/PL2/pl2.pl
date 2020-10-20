% Media dos elementos de uma lista
media(L, R) :-
	media(L, 0, 0, R).

media([], S , C, R) :-
	R is S / C.

media([H|T], S, C, R) :-
	S1 is H + S, 
	media(T, S1, C+1, R).

% Menor valor lista

menor([H|T], R) :-
	menor(T, H, R).

menor([], R, R) :- !.

menor([H|T], R0, R) :-
	M is min(H, R0),
	menor(T, M, R).

% Num elementos pares e impares

num_pares_e_impares(L, P, I) :-
	num_pares_e_impares(L, 0, 0, P, I).

num_pares_e_impares([], P, I, P, I) :- !.

num_pares_e_impares([H|T], P0, I0, P, I) :-
	L is mod(H,2),
	L == 0,
	P1 is P0 + 1,
	num_pares_e_impares(T, P1, I0, P, I).

num_pares_e_impares([H|T], P0, I0, P, I) :-
	L is mod(H,2),
	L \== 0,
	I1 is I0 + 1,
	num_pares_e_impares(T, P0, I1, P, I).

% Membro de uma lista

membro(H, [H|_]).

membro(E, [_|T]) :-
	membro(E,T).

% Verificar se lista tem elementos repetidos

contem_elem_repetidos([H|T]) :-
	membro(H, T).

contem_elem_repetidos([H|T]) :-
	not(membro(H, T)),
	contem_elem_repetidos(T).

% Colocar o menor elemento á frente da lista

menor_elem_frente(L, RES) :-
	menor(L, R),
	apagar_primeiro(L, R, L1),
	concatenacao([R], L1, RES).

% Concatenação de duas listas

concatenacao([],L,L).

concatenacao([H1|L1],L2,[H1|L3]):-
	concatenacao(L1,L2,L3).

% Mete a lista pequena

lista_pequena([], []) :- !.
lista_pequena([H|T], F) :-
    !,
    lista_pequena(H, H1),
    lista_pequena(T, T1),
    concatenacao(H1, T1, F).
lista_pequena(H, [H]).

% Apagar todas as ocorrencias

apagar_todas_ocurrencias([], _, []).

apagar_todas_ocurrencias([H|T], H, R) :-
	apagar_todas_ocurrencias(T, H, R).

apagar_todas_ocurrencias([H|T], E, [H|R]) :-
	apagar_todas_ocurrencias(T, E, R).
	

% Apagar primeira ocorrencia

apagar_primeiro([], _, []) :- !,false.

apagar_primeiro([H|T], H, T).

apagar_primeiro([H|T], E, [H|R]) :-
	apagar_primeiro(T, E, R).

% Substituir todas as ocorrencias

sub_todas(_, _, [], []).

sub_todas(E, M, [E|T], [M|R]) :-
	sub_todas(E,M,T,R).

sub_todas(E, M, [H|T], [H|R]) :-
	sub_todas(E, M, T, R).

% Inserir um elemento numa dada posicao da lista

inserir_elemento(E, P, L, R) :-
	inserir_elemento(E, P , 1, L, R).

inserir_elemento(_, _, _, [], []) :- !,false.

inserir_elemento(E, P, P, L, [E|L]).

inserir_elemento(E, P, C, [H|T], [H|R]) :-
	C1 is C + 1,
	inserir_elemento(E, P, C1, T, R).

% Inverter uma lista

inverter_lista(L,R) :- 
	inverter_lista(L,[],R).

inverter_lista([],R,R).

inverter_lista([H|T],A,R) :- 
	inverter_lista(T, [H|A], R).

% União Listas

uniao(L, O, R) :-
	uniao(L, O, R, []).

uniao([],[],R,R).

uniao([],O,R,L):-
	uniao(O,[],R,L).

uniao([H|T], O, R, L) :-
	membro(H, L),
	uniao(T, O, R, L).

uniao([H|T], [H|T1], R, L) :-
	not(membro(H,L)),
	uniao(T,T1,R,[H|L]).

uniao([H|T], O, R, L) :-
	not(membro(H, L)),
	uniao(T, O, R, [H|L]).

% Interseção Listas

intersecao([],_,[]).

intersecao([H|T], L, R) :-
	not(membro(H, L)),
	intersecao(T, L, R).

intersecao([H|T], L, [H|R]) :-
	membro(H, L),
	intersecao(T, L, R).

% Diferença de Listas

%Chama-se diferença frontal pois só cria uma lista com a diferença da lista do primeiro argumento("a frente")
diferenca_frontal([],_,[]).

diferenca_frontal([H|T], L, R) :-
	membro(H,L),
	diferenca_frontal(T, L, R).

diferenca_frontal([H|T], L, [H|R]) :-
	not(membro(H, L)),
	diferenca_frontal(T, L, R).

diferenca(L, O, R) :-
	diferenca_frontal(L, O, R1),
	diferenca_frontal(O, L, R2),
	concatenacao(R1,R2,R).
