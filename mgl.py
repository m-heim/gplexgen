#!/usr/bin/env python
import graphviz
import dataclasses
import re

@dataclasses.dataclass
class state:
    id: int
        
@dataclasses.dataclass
class node:
    id: int
    edges: list
    
    
@dataclasses.dataclass
class rule:
    name: str
    pattern: re.Pattern


def read_rules(file_path: str):
    rules = []
    delimiter = '::='
    with open(file_path, 'r') as file_reader:
        data = file_reader.read()
        for row in data.splitlines():
            index = row.index(delimiter)
            identifier = row[:index].rstrip()
            pattern = row[index + len(delimiter):]
            rules.append(rule(identifier, re.compile(pattern)))
    return rules
    
def main():
    print(read_rules())
    dot = graphviz.Digraph()
    dot.node('start')
    
        
if __name__ == '__main__':
    main()