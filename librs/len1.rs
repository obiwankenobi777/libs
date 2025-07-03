use std::env;
fn main() {
    let args:Vec<String> = env::args().collect();

    if args.len() < 2 {
        eprintln!("Erro!\nParemetros Ausentes!");
        std::process::exit(1);
    }

    let mut i: usize = 1;
    let mut sum: usize = 0;
    while i < args.len() {
        println!("[{i}] {} -> {}", args[i], args[i].len());
        sum += args[i].len();
        i += 1;
    }
    println!("\nwords -> {}", i - 1);
    println!("characters -> {}", sum);
}
