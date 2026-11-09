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
    connection[bash.sh\n//n-Docker-Files_estimate_via_docker-ps]
    subgraph Evaluate
        output[main.cpp]
        Klasse1[ServerPort.h]
        Klasse2[ErrorDetector.h]
        Klasse4[Stack.h]
        klasse5[Item.h]
        Klasse2 --> klasse5
        Klasse1 --> output
        klasse5 --> Klasse4
        Klasse4 --> output
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
 
connection --> Logs
connection -->  Klasse2
server --> ai
server --> Klasse1
Klasse1 --> server 
server --> UI

Klasse1 --> sharedErrorDB



