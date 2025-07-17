use std::env;

fn gcd(u: u128, v: u128) -> u128 {
    if v > 0 {
        gcd(v, u % v)
    } else {
        u
    }
} 
fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 3 {
        eprintln!("ERROR!\nTwo parameters are required!");
        std::process::exit(1);
    }
    let u = match args[1].trim().parse::<u128>() {
        Ok(n) => n,
        Err(_) => {
            eprintln!("ERROR!\nInvalid Argument: {}", args[1]);
            std::process::exit(1);
        },
    };
    let v = match args[2].trim().parse::<u128>() {
        Ok(n) => n,
        Err(_) => {
            eprintln!("ERROR!\nInvalid Argument: {}", args[2]);
            std::process::exit(1);
        },
    };
    println!("gcd({u}, {v}) = {}", gcd(u, v));

}

