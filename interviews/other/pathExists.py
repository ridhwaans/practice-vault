'''
Given a road network, could be bidirectional, determine if a path exists between an origin and destination node
'''

from collections import defaultdict
class Graph():
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, origin_vertice, destination_vertice):
        self.graph[origin_vertice].append(destination_vertice)

    def get_adjacent_vertices(self, vertice):
        return self.graph[vertice]

    def path_exists(self, origin, destination): 
        # Create a queue for BFS 
        queue=[] 
        visited =[False]*(len(self.graph.keys()))
        # Start at the origin
        queue.append(origin) 
        visited[origin] = True
        while queue: 
            #Dequeue
            n = queue.pop(0) 
            if n == destination: 
                return True
            for i in self.graph[n]: 
                if visited[i] == False: 
                    queue.append(i)
                    visited[i] = True
        return False

road_network = Graph() 
road_network.add_edge(0, 1) 
road_network.add_edge(0, 2) 
road_network.add_edge(1, 2) 
road_network.add_edge(2, 0) 
road_network.add_edge(2, 3) 
road_network.add_edge(3, 3) 
  
true_cases = [(1,3)]
false_cases = [(3,1)]

for start,end in true_cases:
    print "Does path exist from {0} to {1}?: {2}".format(start, end, road_network.path_exists(start,end))
for start,end in false_cases:
    print "Does path exist from {0} to {1}?: {2}".format(start, end, road_network.path_exists(start,end))