struct Rule {
    name: String,
    pattern: String
}

fn main() {
    let rule = Rule{name:String::from("rule1"), pattern:String::from("pattern1")};
    println!("{}", rule.name);
    println!("{}", rule.pattern);
    return ();
}