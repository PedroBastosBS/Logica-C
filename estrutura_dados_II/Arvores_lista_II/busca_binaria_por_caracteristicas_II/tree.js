const Node = require('./node')
const fs = require('fs')

class Tree {
    constructor() {
        this.root = null
    }

    insert(hair, eye, skin, name) {
        this.root = this.recursiveInsert(this.root, hair, eye, skin, name)
    }

    recursiveInsert(current, hair, eye, skin, name) {
        if (current === null) {
            current = new Node(hair, eye, skin)
            current.data.push(name)
        } else if (current.hair === hair && current.eye === eye && current.skin === skin) {
            current.data.push(name)
        } else if (hair < current.hair) {
            current.left = this.recursiveInsert(current.left, hair, eye, skin, name)
        } else {
            current.rigth = this.recursiveInsert(current.rigth, hair, eye, skin, name)
        }
        return current
    }

    getAll(hair, eye, skin) {
        this.findAllRecursive(this.root, hair, eye, skin)
    }

    findAllRecursive(current, hair, eye, skin) {
        if (current === null) {
            return
        }
        if (current.hair === hair && current.eye === eye && current.skin === skin) {
            console.log(current.data)
        }
        this.findAllRecursive(current.left, hair, eye, skin)
        this.findAllRecursive(current.rigth, hair, eye, skin)
    }

    findByPerson(hair, eye, skin, name) {
        this.findByPersonRecursive(this.root, hair, eye, skin, name)
    }

    findByPersonRecursive(current, hair, eye, skin, name) {
        if (current === null) {
            console.log(`${name} not found`)
            return
        }
        if (current.hair === hair && current.eye === eye && current.skin === skin) {
            if (current.data.includes(name)) {
                console.log(`${name} found.`)
            } else {
                console.log(`${name} not found.`)
            }
            return
        }
        this.findByPersonRecursive(current.left, hair, eye, skin, name)
        this.findByPersonRecursive(current.rigth, hair, eye, skin, name)
    }

    printDataBase() {
        this.printDateBaseRecursive(this.root)
    }

    printDateBaseRecursive(current) {
        if (current === null) {
            return
        }
        console.log(`Hair: ${current.hair}, Eye: ${current.eye}, Skin: ${current.skin}, People: ${current.data}`)
        this.printDateBaseRecursive(current.left)
        this.printDateBaseRecursive(current.rigth)
    }

    saveDB() {
        try {
            const stream = fs.createWriteStream('db.txt')
            this.saveDBRecursive(this.root, stream)
            stream.end()
            console.log(`save in database`)
        } catch (error) {
            console.error(`Error: ${error}`)
        }
    }

    saveDBRecursive(node,stream) {
        if(node !== null) {
            this.saveDBRecursive(node.left, stream)
            stream.write(`Hair: ${node.hair}, Eye: ${node.eye}, Skin: ${node.skin}\n`)
            stream.write(`People: ${node.data.join(' ')}\n`)
            this.saveDBRecursive(node.rigth, stream)
        }

        console.log('Save in dataBase')
    }

    loadDB() {
        this.root = null;
        try {
            const data = fs.readFileSync('db.txt', 'utf-8');
            const rows = data.split('\n');
    
            for (const item of rows) {
                if (item && item.trim()) {
                    const info = item.trim().split(": ");
                    
                    if (info.length >= 2) {
                        const caracteristics = info[1].split(", ");
                        
                        if (caracteristics.length >= 3) {
                            const hair = caracteristics[0].split(" ")[1];
                            const eye = caracteristics[1].split(" ")[1];
                            const skin = caracteristics[2].split(" ")[1];
                            
                            if (info.length >= 3) {
                                const people = info[2].split(": ")[1].split(" ");
                                
                                for (const person of people) {
                                    this.insert(hair, eye, skin, person);
                                }
                            }
                        }
                    }
                }
            }
            
        } catch (error) {
            console.error(`Error: ${error}`);
        }
    }
}

let tree = new Tree()
tree.insert("Loiro", "Azul", "Branca", "João")
tree.insert("Loiro", "Azul", "Branca", "Maria")
tree.insert("Preto", "Verde", "Parda", "Carlos")
tree.getAll("Loiro", "Azul", "Branca")
tree.findByPerson("Preto", "Verde", "Parda", "Carlos")
tree.printDataBase()
tree.saveDB()
tree.loadDB()
