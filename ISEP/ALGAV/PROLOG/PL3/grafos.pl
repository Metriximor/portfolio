liga(a,b).
liga(a,c).
liga(a,d).
liga(b,e).
liga(b,f).
liga(c,f).
liga(c,g).
liga(d,a).
liga(d,g).
liga(d,h).
liga(d,i).
liga(e,j).
liga(f,a).
liga(f,j).
liga(f,k).
liga(g,f).
liga(g,o).
liga(g,h).
liga(h,d).
liga(h,l).
liga(i,l).
liga(j,m).
liga(j,n).
liga(k,n).
liga(k,p).
liga(l,p).

% Primeiro em Profundidade
dfs(E,E,[E],_).

dfs(S,E,[S|C],Exp):- %Exp está aqui para evitar loops infinitos
    not(member(S,Exp)),
    liga(S,S1),
    dfs(S1,E,C,[S|Exp]).

dfs(S,E,[S|C]):-
    liga(S,S1),
    dfs(S1,E,C,[S]).

%Encontrar todas as soluções

encontrar_todos_dfs(S,E,C):-
    findall(L, dfs(S,E,L), C).

%Solução que passe por menos nós

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

solucao_curta_dfs(S,E,C):-
    findall(L1, dfs(S,E,L1), L),
    lista_mais_pq(L, C).

%Nivel de corte

dfs_corte(E,E,[E],_,_,_).

dfs_corte(S,E,[S|C],Exp,Max,Corte):- %Exp está aqui para evitar loops infinitos
    Corte1 is Corte + 1,
    Corte1 < Max,
    not(member(S,Exp)),
    liga(S,S1),
    dfs_corte(S1,E,C,[S|Exp],Max,Corte1).

dfs_corte(S,E,[S|C],Corte):-
    liga(S,S1),
    dfs_corte(S1,E,C,[S],Corte,0).

%Pesquisa de largura

bfs(Orig,Dest,Cam):-
    bfs2(Dest,[[Orig]],Cam).

bfs2(Dest,[[Dest|T]|_],Cam):-
    reverse([Dest|T],Cam).

bfs2(Dest,[LA|Outros],Cam):-
    LA=[Act|_],
    findall([X|LA],
        (Dest\==Act,liga(Act,X),\+ member(X,LA)),
        Novos),
    append(Outros,Novos,Todos),
    bfs2(Dest,Todos,Cam).