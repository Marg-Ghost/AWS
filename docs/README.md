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
    UI_Client --> Server
    DB --> UI_Client
  end
  
subgraph Check-Client
    connection[bash.sh]
    subgraph Evaluate
        output[main.cpp]
        Klasse1[DockerSocketListener.h]
        Klasse2[ApiClient.h]
        Klasse3[LogRingBuffer.h]
        
        Klasse1 --> output
        Klasse2 --> output
        Klasse3 --> output
    end  
    connection --> output
    output --> connection  
  end
subgraph Controller
    server[server.py]
    DockerDB[(AllDockerContainer\nSQLite)]
    server --> DockerDB
end
  
 subgraph AI-Connect
    ai[ai.py]
    API[AWS-API]
    RDB[(PastErrors\nCromaDB)]
    ai --> RDB
    RDB --> ai
    ai --> API
   end
   
 subgraph UI
    web[Webpage: HTML/CSS/JS]
 end
  
  
connection --> Docker-Client
output --> Controller
Controller --> ai
server --> output
server --> UI




