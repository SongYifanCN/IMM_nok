import networkx as nx
import numpy as np
import math
import random

n = 16000000
m = 0
'''
with open('test', 'w') as f:
    f.write(str(n) + ' ' + str(n) + '\n')
    for i in range(int(n/2)-1):
        m+=1
        f.write(str(i) + '\t' + str(i+1) + '\n') 
    m+=1
    f.write(str(int(n/2)-1) + '\t' + str(0) + '\n')
    for i in range(int(n**0.5)):
        for j in range(int(int(n**0.5)/2-1)):
            m+=1
            f.write(str(int(n/2)+i*int(int(n**0.5)/2)+j) + '\t' + str(int(n/2)+i*int(int(n**0.5)/2)+j+1)+ '\n')
        m+=1
        f.write(str(int(n/2)+(i+1)*int(int(n**0.5)/2)-1) + '\t' + str(int(n/2)+i*int(int(n**0.5)/2))+ '\n')
with open('attribute.txt', 'w') as f:
    f.write('n='+str(n) + '\n')
    f.write('m='+str(m) + '\n')

'''
with open('graph_lt.inf', 'w') as f:
    for i in range(int(n/2)-1):
        m+=1
        f.write(str(i) + ' ' + str(i+1) + ' ' + '1.0' + '\n') 
    m+=1
    f.write(str(int(n/2)-1) + ' ' + str(0) + ' ' + '1.0' + '\n')
    for i in range(int(n**0.5)):
        for j in range(int(int(n**0.5)/2-1)):
            m+=1
            f.write(str(int(n/2)+i*int(int(n**0.5)/2)+j) + ' ' + str(int(n/2)+i*int(int(n**0.5)/2)+j+1) + ' ' + '1.0' + '\n')
        m+=1
        f.write(str(int(n/2)+(i+1)*int(int(n**0.5)/2)-1) + ' ' + str(int(n/2)+i*int(int(n**0.5)/2)) + ' ' + '1.0' + '\n')
with open('attribute.txt', 'w') as f:
    f.write('n='+str(n) + '\n')
    f.write('m='+str(m) + '\n')
