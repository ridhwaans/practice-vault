# Zookeeper
#
# Implement a simplified version of zookeeper, a key value store
#
# Zookeeper requires all of the names/keys to look like paths in a filesystem, so a name is a sequence of path elements separated by a slash ("/").
# Every mapping has a parent whose path is a prefix with one less element; the exception to this rule is root ("/") which has no parent.
# Unlike a regular file system, all these mappings can have both data (so it acts like a file) and children (so it acts like a directory)
#
# /
# /app1, /app2 ...
# /app1/p1, /app1/p2, /app1/p3 ...
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
    store = {"/"}
    def create(self, path, value):
        if validate(self.path):
            self.store[path] = value
        else:
            raise KeyError

    def update(self, path, value):
        if path in store.values():
            self.store[path] = value
        else:
            raise KeyError

    def validate(self, path):
        if path is None:
            return False
        if len(path) == 0:
            return False
        if path[0] != "/":
            return False
        if path[0:path.rindex["/"]] not in self.store.keys():
            return False
        if path in self.store.keys():
            return False
        return True

zk = Zookeeper()
zk.create("/app1/p1", "/app1/p1 value")
print(zk.read("/app1/p1"))
zk.create("/app1/p1", "/app1/p1 value")
print(zk.read("/app1/p1"))
zk.create("/p1/p1", "/p1/p1 value")
print(zk.read("/p1/p1"))
zk.create("/p1", "/p1 value")
print(zk.read("/p1"))
zk.create("/p1/p1", "/p1/p1 value")
print(zk.read("/p1/p1"))