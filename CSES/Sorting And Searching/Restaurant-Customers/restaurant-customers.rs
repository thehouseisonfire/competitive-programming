use std::io::Read;

fn main() {
    let mut buf = String::new();
    std::io::stdin().lock().read_to_string(&mut buf).unwrap();
    let mut iter = buf.split_ascii_whitespace().map(|x| x.parse().unwrap());
    let n: usize = iter.next().unwrap();
    let mut numbers1 = Vec::with_capacity(n);
    let mut numbers2 = Vec::with_capacity(n);
    for _ in 0..n {
        numbers1.push(iter.next().unwrap());
        numbers2.push(iter.next().unwrap());
    }
    numbers1.sort_unstable();
    numbers2.sort_unstable();
    let (mut i, mut j, mut count, mut max_count) = (0, 0, 0, 0);
    loop {
        if numbers1[i] < numbers2[j] {
            count += 1;
            i += 1;
            if count > max_count {
                max_count += 1;
            }
        } else {
            count -= 1;
            j += 1;
        }
        if i == n {
            break;
        }
    }
    println!("{max_count}");
}
