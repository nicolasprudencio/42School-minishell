# 42School-minishell
This program simulates an executable shell environment

#Parser functionality;  

The parser will utilize of a pushdown automaton with a finite set of states initialized to parse the desired language to create a command table based on the tokens provided by the lexer.  

If, at any point during parsing of the tokens the automaton find a non-action, or a FALSE_INDEX, the parser will return NULL.  

##The Automaton;  

The automaton consists of several elements, the states of the automaton act as the modes of operation, it's a set of numbers, each relating to a single mode of operation, the automaton starts in its 'starting state' and wherever it stops operating (reach the end of the input string) it will either be in one of its accepting states or not, if not, the parsing has found an error in the input.  
The input alphabet of the automaton is a set of all possible inputs it can receive, while its stack alphabet is all possible itens that can exist in its stack, the stack will always start with the automaton's initial symbol on top of it. The stack is a auxiliar tool for the automaton, it allows it to check for its relations.  

The transitions of the automaton will define how it will act when finding a specfic combination of input and symbol on top of the stack.  

The language of the automaton is a structure containing all the values for the language to be parsed.  

The automaton works duo to a set of functions:  

- automaton_new:  
    this function will be responsible for the intial allocation of all parts of the automaton, it will give it all the tools needed for it to do its job.  

- automaton_states:  
    This function will fill the set of states of the automaton.  

- automaton_astates:  
    This function will fill the set of all accepting states of the automaton.  

- automaton_transition_relation:  
    This function will fill the set of all transition relations of the automaton.  

- automaton_act:  
    This function will give to the automaton the next token to be read as an input, then the automaton will analyse it against its relations, using the stack as a tool. It will return the action to take, and, also, change its pop and push its stack as needed. The return is FALSE_INDEX if the there is no action to be taken in the situation.  

- automaton_find_transition:  
    This function will loop all the possible transitions the automaton can make, and, when a valid transition is found, return its value, otherwise, if no transition is valid in the situation, FALSE_INDEX will be returned.  
