use std::env;
fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        eprintln!("Error!\nMissing Parameters!");
        std::process::exit(1);
    }
    let number: i128 = match args[1].trim().parse() {
        Ok(v) => v,
        Err(_) => 0,
    };
    println!("The Factorial of ({number}) is: {}", fact(number));
}
fn fact(n: i128) -> i128 {
    if n == 1 || n == 0 { 1 } else { n * fact(n - 1) }
}
