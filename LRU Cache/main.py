class Node:
    def __init__(self, k, val):
        self.key = k
        self.value = val
        self.next = None
        self.prev = None


class LRUCache:

    def remove(self, node):
        ne = node.next
        prev = node.prev

        prev.next = ne
        ne.prev = prev

    def insert(self, node):
        prev = self.tail.prev

        prev.next = node
        self.tail.prev = node
        node.next = self.tail
        node.prev = prev

    def __init__(self, capacity: int):
        self.mp = {}
        self.head = Node(-1, -1)
        self.tail = Node(-1, -1)
        self.capacity = capacity

        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        if key in self.mp:
            self.remove(self.mp[key])
            self.insert(self.mp[key])

            return self.mp[key].value

        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.mp:
            self.remove(self.mp[key])

        node = Node(key, value)
        self.mp[key] = node
        self.insert(node)

        if len(self.mp) > self.capacity:
            first = self.head.next
            self.remove(first)

            del self.mp[first.key]
