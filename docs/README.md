# Project Overview

```mermaid
---
config:
  htmlLabels: false
---
flowchart LR
 
subgraph Docker-Client
    Server[server.py]
    UI_Client[Web app]
    DB[(Datbase)]
    Logs[Log\n.txt]
    UI_Client --> Server
    DB --> UI_Client
    
    Server --> Logs
    UI_Client --> Logs
    DB --> Logs
end

subgraph Check-Client
    txt1[get_container.sh]
    txt2[get_logs.sh]
    subgraph Evaluate
        output[main.cpp]
        Klasse1[ServerPort.h]
        Klasse2[ErrorDetector.h]
        Klasse4[Stack.h]
        Klasse5[Item.h]
        Klasse6[Database]
        Klasse7[DockerSystem.h]
        Klasse1 --> output
        
        subgraph Trie
            KlasseA[Trie.h]
            ErrorList["ErrorWord.txt"]
            
        end
        Klasse2 --> KlasseA
        KlasseA --> ErrorList
        txt1 --> Klasse6 --> output
        output --> txt2 
        txt2 --> Klasse5
        Klasse5 --> Klasse4
        Klasse4 --> Klasse2
        Klasse2 --> Klasse7
        Klasse7 --> output
    end  
  end
  
subgraph Controller
    server[server.py]
    DockerDB[(AllDockerContainer\nid : Name : Type : Importance\nSQLite)]
    sharedErrorDB[(Shared Intel Error\nid : Error\nSQLite)]
    server --> DockerDB
    server --> sharedErrorDB
end
  
 subgraph AI-Connect
    ai[ai.py]
    API[AWS-API]
    RDB[(PastErrors\n->Error...to fix ...\nCromaDB)]
    ai --> RDB
    RDB --> ai
    ai --> API
   end
   
 subgraph UI
    web[Webpage: HTML/CSS/JS]
 end
 


server --> ai
server --> Klasse1
Klasse1 --> server 
server --> UI
txt1 --> Docker-Client
txt2 --> Logs
Klasse1 --> sharedErrorDB



