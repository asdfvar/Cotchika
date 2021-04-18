import numpy as np
import copy

class Map:
   def __init__ (self, size, numDomains):
      self.domains = []
      for domain in range (numDomains):
         self.domains.append (np.zeros (size, dtype = float))

class Unit:
   def __init__ (self, hp, ac, domain):
      self.hp = hp
      self.ac = ac
      self.domain = domain

# domain - N-dimensional array with cost values associated with each cell.
#          Values < 0 indicate obstacles
def find_path (domain, start, destination):
   cost = np.zeros (np.shape (domain))
   cost[tuple (start)] = 1.0
   step_cost = 1.0

   current_index = start
   found         = False
   updated       = True

   while not found and updated:
      updated = False

      ###################################################################################
      # Update or check neighboring cells biased on the direction toward the destination.
      # Directions will be checked using the 4 cardinal directions
      ###################################################################################

      desired_direction = destination - current_index

      # Sort in descending order (it's desired to step in the direction with the greatest
      # distance available)
      direction_order = np.argsort (np.abs (desired_direction))[::-1]

      for direction in direction_order:
         # From the current index, update in the currently desired direction
         candidate_index = copy.deepcopy (current_index)
         candidate_index[direction] += np.sign (desired_direction[direction])

         # Check edge conditions or obstacles
         if candidate_index[direction] < 0: continue
         if candidate_index[direction] >= np.shape (cost)[direction]: continue
         if domain[tuple (candidate_index)] < 0.0: continue

         # Update the cost function if there's no associated cost here (cost <= 0)
         if cost[tuple (candidate_index)] <= 0.0: #
            cost[tuple (candidate_index)] =                   \
                  cost[tuple (current_index)] +               \
                  step_cost + domain[tuple (candidate_index)]
            current_index = candidate_index
            updated = True
            break

         # Update the cost function appropriately if it's a cheaper option than what's there
         elif cost[tuple (candidate_index)] > \
               cost[tuple (current_index)] +  \
               step_cost                   +  \
               domain[tuple (candidate_index)]: #
            cost[tuple (candidate_index)] =     \
                  cost[tuple (current_index)] + \
                  step_cost                   + \
                  domain[tuple (candidate_index)]
            current_index = candidate_index
            updated = True
            break

   if all (current_index == destination): found = True

   # TODO: redo this but instead step along the edge of possible updates to bias the one closest to the destination

   return cost
