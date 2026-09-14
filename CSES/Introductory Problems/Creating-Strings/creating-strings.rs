use std::{fmt::Write, io::Read};

fn factorial(n: usize) -> usize {
    if n < 3 {
        return n;
    }
    let mut results = vec![0; n + 1];
    results[2] = 2;
    for i in 3..=n {
        results[i] = i * results[i - 1];
    }
    results[n]
}

fn formula(str: &[u8]) -> usize {
    let mut alphabet = [0usize; 26];
    for &c in str {
        alphabet[(c - b'a') as usize] += 1;
    }
    let result = factorial(str.len());
    let mut divide = 1;
    for i in 0..26 {
        if alphabet[i] > 1 {
            divide *= factorial(alphabet[i]);
        }
    }
    result / divide
}

fn next_permutation(str: &mut [u8]) {
    let mut i = str.len() - 2;
    while str[i] >= str[i + 1] {
        i -= 1;
    }
    let mut j = str.len() - 1;
    while str[j] <= str[i] {
        j -= 1;
    }
    str.swap(i, j);
    str[i + 1..].reverse();
}

fn main() {
    let mut read = String::with_capacity(69);
    std::io::stdin().lock().read_to_string(&mut read).unwrap();
    let mut str = read.trim().as_bytes().to_vec();
    let mut ammount = formula(&str);
    str.sort_unstable();
    let mut write = String::with_capacity(ammount * (str.len() + 1));
    writeln!(write, "{}", ammount).unwrap();
    writeln!(write, "{}", std::str::from_utf8(&str).unwrap()).unwrap();
    ammount -= 1;
    while ammount > 0 {
        next_permutation(&mut str);
        writeln!(write, "{}", std::str::from_utf8(&str).unwrap()).unwrap();
        ammount -= 1;
    }
    print!("{}", write);
}
