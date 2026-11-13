import sqlite3
import os

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, id, importance):
        new_node = Node(id, importance)
        if not self.head:
            self.head = new_node
            return

        self.head.append(new_node)

    def pop(self):
        if not self.head:
            return None

        popped_node = self.head
        self.head = self.head.next
        return popped_node

    def remove_node(self, node_to_remove):
        if not self.head:
            return

        if self.head == node_to_remove:
            self.head = self.head.next
            return
        else:
            self.head.remove_node(node_to_remove)

    def sort_by_importance(self) -> 'LinkedList':
        # Implementing modified selection sort for linked list
        sorted_list = LinkedList()

        if not self.head:
            return sorted_list
        elif not self.head.next:
            sorted_list.append(self.head.id, self.head.importance)
            return sorted_list

        current = self.head
        if current.importance == 5:
            sorted_list.append(current.id, current.importance)
            current = current.next
        else:
            highest_node = self.get_highest_importance_node()
            sorted_list.append(highest_node.id, highest_node.importance)
            self.remove_node(highest_node)

        return sorted_list


    def get_highest_importance_node(self) -> 'Node':
        if not self.head:
            return None
        highest = self.head.importance
        if self.head.importance == 5:
            return self.head
        else:
            return self.head.get_highest_importance_node(highest, self.head)

class Node:
    def __init__(self, id, importance):
        self.id = id
        self.importance = importance
        self.next = None

    def append(self, new_node):
        if not self.next:
            self.next = new_node
        else:
            self.next.append(new_node)

    def remove_node(self, node_to_remove):
        if self.next == node_to_remove:
            self.next = self.next.next
        elif self.next:
            self.next.remove_node(node_to_remove)

    def get_highest_importance_node(self, highest, highest_node) -> 'Node':
        if self.importance == 5:
            return self
        
        if self.importance == highest:
            return highest_node

        if self.importance > highest:
            highest = self.importance
            highest_node = self

        if self.next:
            return self.next.get_highest_importance_node(highest, highest_node)
        else:
            return highest_node

def check_all_server():
    conn = sqlite3.connect("data/Docker.db")
    cursor = conn.cursor()
    cursor.execute("SELECT id, importance FROM database_deamon")
    server_intel = cursor.fetchall()

    linked_list = LinkedList()
    for server in server_intel:
        linked_list.append(server[0], server[1])
    linked_list = linked_list.sort_by_importance()

    # For each Request to cpp socket:



    conn.close()
