use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        eprintln!("Error. Missing parametrs!");
        std::process::exit(1);
    }

    let number: i128 = match args[1].trim().parse() {
        Ok(n) => n,
        Err(_) => 0,
    };

    if number < 2 {
        eprintln!("Numbers less than 2 aren't considered prime.");
        std::process::exit(1);
    }

    let mut count: i64 = 0;
    let mut n: i128 = 2;
    let mut divisors: Vec<i128> = Vec::new();

    while n < number {
        if number % n == 0 {
            count += 1;
            divisors.push(n);
        }
        n += 1;
    }

    if count > 0 {
        println!("The number {} isn't a prime number!", number);
        println!("\nTotal divisors: {}", divisors.len());
        println!("{:?}\n", divisors);
    } else {
        println!("The number {} is a prime number!", number);
    }
    println!();
}
