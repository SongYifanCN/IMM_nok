import networkx as nx
import numpy as np
import random
g = nx.complete_graph(4050)
degree = np.zeros(4050)
edgep = []
alledge = 0
for edge in list(g.edges()):
    prob = random.random()
    degree[int(edge[1])] += float(prob)
    edgep.append(prob)
    prob = random.random()
    degree[int(edge[0])] += float(prob)
    edgep.append(prob)

with open('graph_lt.inf', 'w') as f:
    tot = 0
    for edge in list(g.edges()):
        alledge+=2
        f.write(str(edge[0])+' '+str(edge[1])+ ' '+ str(min(1.0,edgep[tot]/degree[int(edge[1])])) + '\n')
        tot+=1
        f.write(str(edge[1])+' '+str(edge[0])+ ' '+ str(min(1.0,edgep[tot]/degree[int(edge[0])])) + '\n')
        tot+=1
    for i in range(0,90):
        tot = 0
        g = nx.complete_graph(45)
        degree = np.zeros(45)
        edgep = []
        for edge in list(g.edges()):
            prob = random.random()
            degree[int(edge[1])] += float(prob)
            edgep.append(prob)
            prob = random.random()
            degree[int(edge[0])] += float(prob)
            edgep.append(prob)
        for edge in list(g.edges()):
            alledge+=2
            f.write(str(edge[0]+i*45+4050)+' '+str(edge[1]+i*45+4050)+ ' '+ str(min(1.0,edgep[tot]/degree[int(edge[1])])) + '\n')
            tot+=1
            f.write(str(edge[1]+i*45+4050)+' '+str(edge[0]+i*45+4050)+ ' '+ str(min(1.0,edgep[tot]/degree[int(edge[0])])) + '\n')
            tot+=1
print(alledge)
with open('attribute.txt', 'w') as f:
    f.write('n='+str(int(4050*2)) + '\n')
    f.write('m='+str(alledge) + '\n')
    