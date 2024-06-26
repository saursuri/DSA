Asked in Google Interview: 04/16/24

Question:

You are given a list of houses grouped into neighborhoods. Houses are painted in colors.

The first input is an array representing house numbers in each neighborhood. One sub-array represents one neighborhood.
Example:

{ {8, 2, 9}, {4, 6, 4}, {4, 5, 1} }

Each house is painted, so the second input is an array representing the color codes for each house. Example:

{ {'r', 'g', 'b'}, {'w', 'c', 'b'}, {'x', 'y', 'b'} }

This means that House 8 is painted in color r, House 2 is g, House 9 is b etc.

Imagine that you can move houses, reorganize the neighborhoods such that the houses in each neighborhood are in
ascending order, and no house numbers are repeated in a neighborhood. The neighborhood structure must be preserved,
meaning that the number of neighborhoods and the number of houses in each neighborhood should remain the same as given.

Here are a couple of possible outputs of how the houses from the example above could be restructured:

{ {1, 2, 4}, {4, 5, 6}, {4, 8, 9} }

{ {1, 4, 6}, {2, 4, 8}, {4, 5, 9} }

Return all houses structured in neighborhoods along with their colors in the new order. If printing it, a
sample output would look like this:

{ {1b, 4b, 6c}, {2g, 4x, 8r}, {4w, 5y, 9b} }
