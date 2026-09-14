use std::io::{self, BufRead};

fn solution(str: &str) -> i32 {
    let mut prev = ' ';
    let mut count = 0;
    let mut best = 1;
    for c in str.chars() {
        if c != prev {
            if count > best {
                best = count;
            }
            count = 0;
        }
        count += 1;
        prev = c;
    }
    best
}

fn main() {
    let mut buf = String::new();
    io::stdin().lock().read_line(&mut buf).unwrap();
    println!("{}", solution(&buf))
}
