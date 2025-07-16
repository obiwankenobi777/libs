use std::env;

fn gcd(u: i128, v: i128) -> i128 {
    if v > 0 {
        gcd(v, u % v)
    } else {
        u
    }
} 
fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        eprintln!("Erro\nParametros Ausentes");
        std::process::exit(1);
    }
    let u = match args[1].trim().parse::<i128>() {
        Ok(n) => n,
        Err(_) => {
            eprintln!("Erro: argumento '{}' invalido", args[1]);
            std::process::exit(1);
        },
    };
    let v = match args[2].trim().parse::<i128>() {
        Ok(n) => n,
        Err(_) => {
            eprintln!("Erro: argumento '{}' invalido", args[2]);
            std::process::exit(1);
        },
    };
    println!("gcd({u}, {v}) = {}", gcd(u, v));

}

