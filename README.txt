HOW TO RUN
----------
C programs:
    gcc 1_rdp_expression.c -o a
    ./a

LEX programs:
    lex 2_keywords.l          (or: flex 2_keywords.l)
    gcc lex.yy.c -o a
    ./a
    (type input, then press Ctrl+D)

SAMPLE INPUTS
-------------
1_rdp_expression.c      a+b*c   (a+b)*c      -> Accepted
                        a+*b                 -> Rejected
2_keywords.l            int x = 25 if total else 7
3_rdp_aSb.c             aabb  ab  (empty)    -> Accepted
                        aab  abab            -> Rejected
4_vowels.l              Hello World          -> Vowels 3, Consonants 7
5_operator_precedence.c i+i*i   (i+i)*i      (use i for id)
6_count.l               any text, Ctrl+D
7_first_set.c           5
                        E->TR
                        R->+TR
                        R->#
                        T->(E)
                        T->i
                        (# = epsilon, capital letters = non-terminals)
8_pos_neg.l             12 -5 +7 3.14 -0.5 .25 -8
