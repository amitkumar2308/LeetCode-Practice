class LRUCache {
public:
    struct Node{
        int key,value;
        Node *prev, *next;
        Node(int k, int v):key(k),value(v), prev(NULL), next(NULL){}
    };

    int cap;
    unordered_map<int,Node*>cache;
    Node *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;

    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->value;
    }
    
    void put(int key, int value) {
         if(cache.find(key)!=cache.end()){
            Node* node = cache[key];
            node->value = value;
            remove(node);
            insert(node);
         }else{
            if(cache.size()==cap){
                Node* lru = tail->prev;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key,value);
            cache[key] = node;
            insert(node);
         }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */