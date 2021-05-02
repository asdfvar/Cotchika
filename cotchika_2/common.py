import numpy as np
from numpy import linalg as la
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

# Generate a cost from the starting location to the destination
# domain - N-dimensional Numpy array with cost values associated with each cell.
#          Values < 0 indicate obstacles
# start  - Tuple value indicating the starting cell

def generate_cost (domain, start, destination):
   cost = np.zeros (np.shape (domain))
   cost[tuple (start)] = 1.0
   step_cost = 1.0

   perimeter = [start]

   current_index = start
   found         = False
   updated       = True

   # Continue to update the cost function until either the destination is found or the cost
   # function is no longer updated
   while destination not in perimeter and len (perimeter) > 0:
      # Find the cell in the perimeter closest to the destination
      min_dist = float ('inf')
      nearest_cell = perimeter[0]
      for cell in perimeter:
         dest_dist = la.norm (np.array (destination) - np.array (cell))
         if dest_dist < min_dist:
            min_dist = dest_dist
            nearest_cell = cell

      # Update the perimeter by checking the neighboring cells for each cell of the perimeter.
      # Any cells that don't have an updated cost will be added to the new list along with the
      # associated cost updated

      cell_cost = cost[nearest_cell]

      #  + + +
      #  + x +
      #  + + +
      cell_offset = [-1 for ind in range (domain.ndim)]
      for dir_count in range (3**domain.ndim):
         new_cell = tuple (np.array (nearest_cell) + np.array (cell_offset))

         if cost[new_cell] >= 0.0 and \
         all (np.array (new_cell) >= 0) and \
         all (np.array (new_cell) < np.shape (domain)):
            domain_cost = domain[new_cell]
            if domain_cost >= 0.0:
               step_dist  = la.norm (cell_offset)

               # The cost is determined by a linear combination of the step distance and the
               # domain cost added to the cost at the current cell
               new_cost = cell_cost + step_dist + domain_cost

               if new_cost < cost[new_cell] or cost[new_cell] == 0.0:
                  cost[new_cell] = new_cost
                  if new_cell not in perimeter:
                     perimeter.append (new_cell)

         # Update the cell offset to the next N-D neighboring cell
         cell_offset[0] += 1
         index = 0
         while cell_offset[index] > 1:
            cell_offset[index] = -1
            index += 1
            if index >= len (cell_offset): break
            cell_offset[index] += 1

      # Remove the originally nearest cell from the perimeter
      perimeter.remove (nearest_cell)

   return cost
