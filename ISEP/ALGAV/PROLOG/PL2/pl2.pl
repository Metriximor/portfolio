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

% Verificar se lista tem elementos repetidos

contem_elem_repetidos([H|T]) :-
	member(H, T).

contem_elem_repetidos([H|T]) :-
	not(member(H, T)),
	contem_elem_repetidos(T).

% Colocar o menor elemento á frente da lista

menor_elem_frente(L, RES) :-
	menor(L, R),
	delete(L, R, L1),
	append([R], L1, RES).

% Concatenação de duas listas

concatenacao([],L,L).

concatenacao([H1|L1],L2,[H1|L3]):-
	concatenacao(L1,L2,L3).

% Mete a lista pequena

lista_pequena(L, L2) :-
	flatten(L, L2).

% Apagar primeira ocorrencia

apagar_primeiro(E, L, R) :-
	delete(E, L, R).

