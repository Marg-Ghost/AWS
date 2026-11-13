
````mermaid
---
config:
  htmlLabels: false
---
flowchart LR

subgraph controller
    Mainserver[server.py]
    ApiConnect[check_client.py]
end
subgraph check_clients
    conn[main.cpp]
    Server[ServerPort.h]
        
    subgraph get_logs
        logs[get_logs.sh\ntakes: $1]
    end
    logs --> conn
end

Mainserver --> ApiConnect
ApiConnect --> Server
Server --> conn
conn --> Mainserver