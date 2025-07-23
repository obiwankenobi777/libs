class Stack {
  #items;
  #count;
  constructor() {
    this.#count = 0;
    this.#items = {};
  }

  isEmpty() {
    return this.#count === 0;
  }

  size() {
    return this.#count;
  }

  push(elem) {
    this.#items[this.#count++] = elem;
  }

  pop() {
    if (this.isEmpty()) {
      return undefined;
    }
    this.#count--;
    const result = this.#items[this.#count];
    delete this.#items[this.#count];

    return result;
  }

  peek() {
    if (this.isEmpty()) {
      return undefined;
    }
    return this.#items[this.#count - 1];
  }

  toString() {
    if (this.isEmpty()) {
      return "";
    }
    let obj = `{ ${this.#items[0]}`;
    for (let i = 1; i < this.#count; ++i) {
      obj = `${obj}, ${this.#items[i]}`;
    }
    obj = obj + " }";
    return obj;
  }

  clear() {
    this.#items = {};
    this.#count = 0;
  }
}
