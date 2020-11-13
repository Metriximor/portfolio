i([],[],[]).
i([H|T],A,[H|B]):-
    member(H,T),!,
    i(T,A,B).
i([H|T],[H|A],B):-
    i(T,A,B).

% i([7,2,1,1,7],A,B).
% i([8,6,7,6,8,1,6,8],A,B).

% 2) fazer uma função que selecione_N/3 que vá buscar 3 resultados a uma lista tipo
% selecione_N(3,['a','b','c','d'],L).
% L = [a,b,c];
% L = [a,b,d];
% L = [a,c,d]; .....

selecione_N(0,[_],[]).
selecione_N(N,[H|T],[H|L]):-
    N1 is N-1,
    selecione_N(N1,T,L).