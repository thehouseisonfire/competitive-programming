use std::io::Read;

fn main() {
    let mut read = String::with_capacity(1000);
    std::io::stdin().lock().read_to_string(&mut read).unwrap();
    let mut str = read.trim().as_bytes().to_vec();
    let mut letters = [0usize; 26];
    for &c in &str {
        letters[(c - b'A') as usize] += 1;
    }
    let mut odds = 0;
    for &l in &letters {
        if l % 2 != 0 {
            odds += 1;
        }
    }
    if odds > 1 {
        println!("NO SOLUTION");
        return;
    }
    let mut start = 0;
    let mut end = str.len() - 1;
    let middle = str.len() >> 1;
    for i in 0..26 {
        if letters[i] % 2 != 0 {
            str[middle] = i as u8 + b'A';
            letters[i] -= 1;
        }
        while letters[i] > 0 {
            str[start] = i as u8 + b'A';
            str[end] = i as u8 + b'A';
            start += 1;
            end -= 1;
            letters[i] -= 2;
        }
    }
    println!("{}", std::str::from_utf8(&str).unwrap());
}
