% Media dos elementos de uma lista
media(L, R) :-
	media(L, 0, 0, R).

media([], S , C, R) :-
	R is S / C.

media([H|T], S, C, R) :-
	S1 is H + S, 
	media(T, S1, C+1, R).
