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

from collections import defaultdict
class Node:
    def __init__(self, node_type):
        self.node_type = node_type
        self.state = 1 # [0,1] if 0 in_use, 1 is free
        
class Server:
    def __init__(self, nodes_dict):
        self.available_nodes = defaultdict(list)
        self.in_use_nodes = defaultdict(list)
        self.prepare_cluster(nodes_dict)
        
    def prepare_cluster(self, num_of_nodes): # O(N*3) time
        for node_type, node_count in num_of_nodes.items():
            
            self.available_nodes[node_type] = [Node(node_type) for _ in range(node_count)]
            
    
    def request_hardware(self, node_type): # O(1) time
        if len(self.available_nodes[node_type]) == 0:
            print('This node type is not available')
            return 
        
        node = self.available_nodes[node_type].pop()
        node.state = 0
        self.in_use_nodes[node_type].append(node)
        
        return node
    
    def release_hardware(self, node): # O(N) time
        if node.state == 1:
            print('The node is already available')
            return 
        
        node_type = node.node_type
        
        num_in_use_nodes = len(self.in_use_nodes[node_type])
        index = 0
        for index in range(num_in_use_nodes):
            if self.in_use_nodes[node_type][index] == node:
                break
        self.in_use_nodes[node_type][index], self.in_use_nodes[node_type][-1] = self.in_use_nodes[node_type][-1], self.in_use_nodes[node_type][index]
        
        self.in_use_nodes[node_type].pop()
        
        node.state = 1
        self.available_nodes[node_type].append(node)
        print('Node released successfully')
    
    
num_nodes = {'T1': 2, 'T2':0, 'T3': 0}
server = Server(num_nodes)

node1 = server.request_hardware('T1')
print('node1 state: ',node1.state)
node2 = server.request_hardware('T1') 
print('node2 state: ',node2.state)

node3 = server.request_hardware('T1')
server.release_hardware(node2)
print('node2 state: ',node2.state)

'''
space complexity: 
O(N) N is the total number of nodes
time complexity: 
request hardware O(1)                
release hardware O(N)
'''