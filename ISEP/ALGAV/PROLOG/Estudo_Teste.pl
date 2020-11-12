totobola([],[]).
totobola([H|T],[X|L]):-
    (is_list(H),!,
    member(X, H),
    totobola(T,L));
    (X is H,
    totobola(T,L)).

ordem([H|_], H, P, P).
ordem([_|T], N, C, P):-
    C1 is C + 1,
    ordem(T, N, C1, P).
ordem_lista(A,B,L):-
    ordem(L,A,0,P1),
    ordem(L,B,0,P2),
    P1<P2.

remove_iguais_seguidos([H|T],R):-
    remiguais(H,T,R).
remiguais(_,[],[]).
remiguais(H,[H|T],R):-
    remiguais(H,T,R).
remiguais(A,[H|T],[A|R]):-
    remiguais(H,T,R).

absoluto([],[],[]).
absoluto([H|T1],[H1|T2],[R|T3]):-
    R is max(H,H1) - min(H,H1),
    absoluto(T1, T2, T3).