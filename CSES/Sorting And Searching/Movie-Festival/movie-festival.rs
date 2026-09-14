use std::{io::Read, println};
fn main() {
    let mut buf = String::new();
    std::io::stdin().lock().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split_ascii_whitespace().map(|x| x.parse().unwrap());
    let n: i32 = iter.next().unwrap();
    let mut pairs: Vec<(i32, i32)> = Vec::with_capacity(n as usize);
    for _ in 0..n {
        pairs.push((iter.next().unwrap(), iter.next().unwrap()));
    }
    pairs.sort_unstable_by(|l, r| l.1.cmp(&r.1));
    let (mut count, mut time) = (0, 0);
    for p in &pairs {
        if time <= p.0 {
            count += 1;
            if time < p.1 {
                time = p.1;
            }
        }
    }
    println!("{count}");
}
