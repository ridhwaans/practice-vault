# This question was asked by Airbnb
#
# Zookeeper
#
# Implement a simplified version of zookeeper, a key value store
#
# Zookeeper requires all of the names/keys to look like paths in a filesystem, so a name is a sequence of path elements separated by a slash ("/").
# Every mapping has a parent whose path is a prefix with one less element; the exception to this rule is root ("/") which has no parent.
# Unlike a regular file system, all these mappings can have both data (so it acts like a file) and children (so it acts like a directory)
#
#                         (tree visualization example)
#                                    "/"  
#                      /                             \
#                  "/app1"                        "/app2" ...
#     /            /         \
# "/app1/p1"  "/app1/p2" "/app1/p3" ... 
#
# create(path, value)
# Creates a new path-value mapping in the zookeeper
# path is a "/" separated pathname like "/app1/p1". value is the value to be stored in the node. 
# create should signal an error to the caller if the path already exists, or if the parent of the path does not exist yet
#
# read(path)
# Returns the value of the mapping represented by path
# read should raise an error if path doesn't already exist
#
# update(path, value)
# Update the value at an already existing mapping
# update should raise an error if path doesn't already exist
#
# After implementing and testing the first three methods, please implement the additional method 
#
# watch(path, watcher)
# Sets a watcher that will be called whenever the watched path or any of its descendants are updated by a call to update or create
# watch accepts path and some sort of listener object (depending on the language this can be a function, pointer, object, or something else)
# Whenever the value of path or that of any of its descendants are set, the callback registered for the path must be called
# The watcher should accept two arguments - the path that was changed and the value that was set

class Zookeeper():
    store = {"/":None}
    def create(self, path, value):
        if self.validate(path):
            self.store[path] = value
        else:
            pass
            #raise KeyError("create error: {} invalid".format(path))
    
    def read(self, path):
        if path in self.store.keys():
            return self.store[path]
        else:
            return "read error: {} does not exist".format(path)
    
    def update(self, path, value):
        if path in self.store.keys():
            self.store[path] = value
        else:
            return "update error: {} does not exist".format(path)

    def validate(self, path):
        if path is None:
            return False
        if len(path.strip()) == 0:
            return False
        if path[0] != "/":
            return False
        if path.rindex("/") == path.index("/"):
            return True
        if path[0:path.rindex("/")] not in self.store:
            return False
        if path in self.store:
            return False
        return True


class WatchableZookeeper(Zookeeper):
    def __init__(self):
        self.listeners = {}
        super().__init__()
        

    def watch(self, path, listener):
        self.listeners.setdefault(path, []).append(listener)
    
    def update(self, path, value):
        super().update(path, value)
        if self.listeners.get(path):
            for listener in self.listeners.get(path):
                listener()
            
    def create(self, path, value):
        super().create(path, value)
        if self.listeners.get(path):
            for listener in self.listeners.get(path):
                listener()

zk = WatchableZookeeper()
zk.create("/app1", "/app1 value")
print(zk.read("/app1"))

zk.create("/app1/p1", "/app1/p1 value")
print(zk.read("/app1/p1"))

zk.create("/p1/p1", "/p1/p1 value")
print(zk.read("/p1/p1"))

zk.create("/p1", "/p1 value")
print(zk.read("/p1"))

zk.create("/p1/p1", "/p1/p1 value")
print(zk.read("/p1/p1"))

def notification():
    print("notification: parent changed")
    
zk.watch("/app1", notification)

zk.update("/app1", "new /app1 value")

zk.update("/p1", "new /p1 value")