class Queue {
  #count;
  #lowestCount;
  #items;

  constructor() {
    this.#count = 0;
    this.#lowestCount = 0;
    this.#items = {};
  }

  isEmpty() {
    return this.#count === 0;
  }

  size() {
    return this.#count - this.#lowestCount;
  }

  enqueue(elem) {
    this.#items[this.#count] = elem;
    this.#count++;
  }

  dequeue() {
    if (this.isEmpty()) {
      return undefined;
    }
    const result = this.#items[this.#lowestCount];
    delete this.#items[this.#lowestCount];
    this.#lowestCount++;
    return result;
  }

  peek() {
    if (this.isEmpty()) {
      return undefined;
    }
    return this.#items[this.#lowestCount];
  }

  clear() {
    this.#items = {};
    this.#count = 0;
    this.#lowestCount = 0;
  }

  toString() {
    if (this.isEmpty()) {
      return undefined;
    } else {
      const list = [];
      for (let i = this.#lowestCount; i < this.#count; ++i) {
        list.push(this.#items[i]);
      }
      return `[${list.join(", ")}]`;
    }
  }

  print() {
    if (this.#count === 0) {
      console.log("Empty queue!");
    } else {
      const list = [];
      for (let i = this.#lowestCount; i < this.#count; ++i) {
        list.push(this.#items[i]);
      }
      console.log(`Queue: [${list.join(", ")}]`);
      console.log(`Queue.size(): ${this.size()}`);
      console.log(`Queue.peek(): ${this.peek()}`);
      console.log(`Queue.isEmpty(): ${this.isEmpty()}`);
    }
  }
}
