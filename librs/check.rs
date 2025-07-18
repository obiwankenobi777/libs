use std::env;

fn main() {
    let s: Vec<String> = env::args().collect();
    if s.len() < 3 {
        eprintln!("Error. 2 parameters are required!");
        std::process::exit(1);
    }

    if s[1] != s[2] {
        eprintln!("They are not equal: {} and {}", s[1], s[2]);
        std::process::exit(1);
    } else {
        println!("They are equals: {} and {}", s[1], s[2]);
    }
}
