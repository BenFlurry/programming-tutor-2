"""
INITIALISATION
start with a single set of randomly (or chosen weights)

EVALUATE FITNESS
evaluate the fitness (tetris game score) of the weights (the actual score you get running tetris all the way through)

MUTATION
each weight, step it down, and up, and see how that changes the fitness score. If it improves, then update the weights and move onto the next weight to test

REPEAT
repeat until the weights dont change after all weights have been stepped up and down. this will be your optimum weights. if it still doesnt score well, then manually (or programmatically) start jumping weights to new values to prevent convergence on local maxima
then start jumping the value of the weight up and down significantly to avoid 

25, 100, 400, 1600
100, 200, 400, 1600
"""

import random


class TetrisAutoplayer:
    def __init__(self, weights=None):
        # Default weights if none are provided
        if weights is None:
            weights = {
                # actually chatgpt generated dont copy for the love of your grade
                "line_clear_weight": 10,
                "move_weight": 1,
                "height_penalty": -0.5,
                "hole_penalty": -1.5,
                "bumpiness_penalty": -0.75,
                "well_depth_penalty": 0.5,
                "tetris_weight": 100
            }
        self.weights = weights
        self.game_score = 0 


    def score_board(self):
        """
        Calculates a move score based on the current weights. 
        This should include evaluating features like line clears, height, holes, etc.
        """
        # Calculate each factor of the move score using weights
        lines_cleared = 0
        aggregate_height = 0
        num_holes = 0
        bumpiness = 0

        # Calculate score using weighted factors
        score = (lines_cleared * self.weights["line_clear_weight"] +
                 self.weights["move_weight"] +
                 aggregate_height * self.weights["height_penalty"] +
                 num_holes * self.weights["hole_penalty"] +
                 bumpiness * self.weights["bumpiness_penalty"])

        return score

    def fitness_function(self):
        """
        Calculates the fitness score for the current set of weights by playing
        a full game and returning the final game score.
        """
        final_score = self.play_game()  # Play a game and get the score
        return final_score
    
    def play_game(self):
        # play a full game here using the weights and scoring function for each board
        pass


def hill_climb(autoplayer, step_size=0.1, max_iterations=1000):
    # initialise with the best weights that weve found so far
    best_weights = autoplayer.weights.copy()
    best_fitness = autoplayer.fitness_function()
    
    # start the hill climbing loop
    for _ in range(max_iterations):
        improved = False
        
        # Try adjusting each weight slightly (this is the hill climbing bit)
        for key in best_weights:
            # try adjusting each weight slightly up or down
            for adjustment in [-step_size, step_size]:
                # Create new candidate weights
                new_weights = best_weights.copy()
                new_weights[key] += adjustment
                
                # Evaluate new weights
                autoplayer.weights = new_weights

                # run the game again and score how well the weights did by the tetris score
                autoplayer.play_game()
                new_fitness = autoplayer.fitness_function()
                
                # Check if the new weights are better
                if new_fitness > best_fitness:
                    # if they are then assign the new weights to our best weights
                    best_weights = new_weights
                    best_fitness = new_fitness
                    improved = True

                    # break out of the adjustment for loop
                    break

            # break out of cycling through the weights to ensure were maximising each weight at a time
            if improved:
                break
        
        # stop if we havent improved, at this point we will re-randomise some of the weights to avoid local max
        if not improved:
            break

    # set the weights to the best ones weve found
    autoplayer.weights = best_weights  
    return best_weights, best_fitness


# Usage Example
if __name__ == "__main__":
    # Initialize the Tetris autoplayer
    autoplayer = TetrisAutoplayer()
    
    # Run hill climbing optimization
    optimized_weights, best_fitness = hill_climb(autoplayer, step_size=0.1, max_iterations=1000)

    print("Optimized Weights:", optimized_weights)
    print("Best Fitness Score:", best_fitness)