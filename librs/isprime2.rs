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

    let mut divisors: Vec<i128> = Vec::new();
    let sqrt_n = (number as f64).sqrt() as i128;

    for i in 2..=sqrt_n {
        if number % i == 0 {
            divisors.push(i);
            if i != number / i {
                divisors.push(number);
            }
        }
    }

    if !divisors.is_empty() {
        println!("The number {} isn't a prime number!", number);
        println!("\nTotal divisors: {}", divisors.len());
        println!("{:?}\n", divisors);
    }
    else {
        println!("The number {} is a prime number!", number);
    }
}
