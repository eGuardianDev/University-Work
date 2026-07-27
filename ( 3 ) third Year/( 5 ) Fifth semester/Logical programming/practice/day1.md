

% member(X,Y)
m_member(X,[X|_]).
m_member(X,[_|T]):- m_member(X,T).


my_append([],L,L).
%my_append([X],L,[X|L]).
my_append([X|T],L,[X|N]):- my_append(T,L,N).


my_len([],0).
my_len([_|T],N) :-
    my_len(T,N1),
    N is N1 + 1.

last(X,[X]).
last(X,[_|T]):- last(X,T).


my_rev([],[]).
my_rev([H|T],L) :-
    my_rev(T,RT),
    append(RT,[H],L).

sum_list([],0).
sum_list([X|T],N):-
    sum_list(T,N1),
    N is N1 + X.


my_rem([_|T],0,T).
my_rem([H|T],N,[H|R]):- 
    N > 0,
    N1 is N - 1,
    my_rem(T,N1,R).

rem1(X,[X|T],T).
rem1(X,[H|T],[H|R]):-
    rem1(X,T,R).








