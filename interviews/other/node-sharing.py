'''
node-sharing
In a server cluster there are three different types of nodes, denoted by T1, T2, T3
Each node is unique. Each node is also limited to one fixed type
The minimum quantity of nodes that can exist in the cluster for each type T1, T2 and T3 is 0 (zero)
There is no upper limit on the number of nodes available in the server cluster for each type T1, T2 and T3

Implement a request_hardware function that does the following:
- given a valid requested node type, looks up the collection of available nodes in the server cluster of the same type and returns one available node of the requested node type, and
- sets the state of the returned node as "in use"
- if there is a zero or no available quantity of nodes of the requested type in the server cluster, it cannot be requested

Implement a release_hardware function that does the following:
- given a valid node whose state is "in use", releases the node back to the server cluster, and
- sets the state of the released node as "free"
- if the given node is already set to a state of "free", it cannot be released
Ending question:
What is the time/space complexity of the data structure/algorithm?
'''