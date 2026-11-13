# Web-App

basic Fastapi framework with js/hmtl/css Forntend 
(we dont need a great Framework for this). However we should manage acces!
Therefore I will add an encryption and a user Table in a SQLite3 DB so we can
be sure only the server Admin and no other person in its subnet can acces the Interface

Login 

```mermaid
---
config:
  htmlLabels: false
---
flowchart LR
subgraph controller
    server[server.py]
end
subgraph data
    User_DB[(login)]
end
subgraph sec
    hash[encryption.py]
end
subgraph web
    conect[main.js]
    UI[index.html]
end

server --> web
server --> sec
sec --> data