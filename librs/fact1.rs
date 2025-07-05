use std::io::{self, Write};
fn main() {
    print!("Write a integer number: ");
    io::stdout().flush().unwrap();

    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();

    let n: i128 = match n.trim().parse() {
        Ok(v) => v,
        Err(_) => 0,
    };
    println!("Fact({n}) = {}", fact(n));
}
fn fact(n: i128) -> i128 {
    if n == 1 || n == 0 { 1 } else { n * fact(n - 1) }
}
