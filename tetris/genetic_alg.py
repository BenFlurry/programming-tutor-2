"""
TRY REMOVING OR LOWERING SLEEP IN VISUAL.PY


INITIALISATION
start with a population of randomly generated individuals, each of them with their own randomly generated weights

FITNESS
run the game on each individual, using their weights to score each board, at the end of the game save the scores of the game to evaluate how good each individual was

SELECTION
select individuals from the population based on their fitness scores. individuals who performed well will have a higher chance of being selected for the next generation.

CROSSOVER (high chance)
with each of these selected individuals, we then combine weights from individuals (which we will call parents) to provide the weights of their childres (maybe take half of the weights from 1 parent and half from the other)

MUTATION (low chance)
introduce random weight changes to a select few individuals to ensure that over-convergence doesnt occur, and keeps the gene pool of the generation diverse

REPLACEMENT (new generation)
form a new generation by replacing the old generation with our new offspring. you can also keep a few very high scoring individuals in order to keep good solutions (elitism)

REPEAT
repeat this process for the number of generations you wish, or until the population converges (where most of the population has similar genes)
"""