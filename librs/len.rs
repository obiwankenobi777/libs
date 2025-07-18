use std::env;
fn main() {
    let args:Vec<String> = env::args().collect();

    if args.len() < 2 {
        eprintln!("Erro!\nParemetros Ausentes!");
        std::process::exit(1);
    }

    let mut sum: usize = 0;
    for (i, j) in args.iter().enumerate().skip(1) {
        println!("[{}] {} -> {}", i, j, j.len());
        sum += j.len();
    }
    println!("\nWords -> {}", args.len() - 1);
    println!("Characters -> {}\n", sum);
}
