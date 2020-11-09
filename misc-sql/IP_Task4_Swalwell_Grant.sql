

CREATE TABLE Accounts (
    actnum INT PRIMARY KEY CHECK(actnum > 100000),
);

CREATE TABLE Departments (
    dnum INT,
    details INT,

    PRIMARY KEY(dnum)
);

CREATE TABLE DepartmentAccounts (
    dnum INT PRIMARY KEY FOREIGN KEY REFERENCES Departments(dnum),
    actnum INT FOREIGN KEY REFERENCES Accounts(actnum),
    est DATE,
    cost INT,    

);

CREATE TABLE Processes (
    pid INT PRIMARY KEY,
    dept INT FOREIGN KEY REFERENCES Departments(dnum),
    cat NVARCHAR(6) CHECK(cat = 'paint' OR cat = 'fit' OR cat = 'cut')
);

CREATE TABLE CuttingProcesses (
    pid INT PRIMARY KEY FOREIGN KEY REFERENCES Processes(pid),

    ctype NVARCHAR(64),
    mtype NVARCHAR(64),
    
);

CREATE TABLE PaintingProcesses (
    pid INT PRIMARY KEY FOREIGN KEY REFERENCES Processes(pid),

    ptype NVARCHAR(64),
    pmeth NVARCHAR(64),
);

CREATE TABLE FittingProcesses (
    pid INT PRIMARY KEY FOREIGN KEY REFERENCES Processes(pid),
    ftype NVARCHAR(64),
);

CREATE TABLE ProcessAccounts (
    pid INT PRIMARY KEY FOREIGN KEY REFERENCES Processes(pid),
    actnum INT FOREIGN KEY REFERENCES Accounts(actnum),
    est DATE,
    cost INT,    
);


Create TABLE Customers (

    cname VARCHAR(64),
    caddress VARCHAR(64),
    ccategory INT,

    PRIMARY KEY(cname)
);

CREATE TABLE Assemblies (
    aid INT,
    cname VARCHAR(64),
    ord DATE,
    details INT,

    PRIMARY KEY(aid),
    FOREIGN KEY (cname) REFERENCES Customers (cname)
  
);

CREATE TABLE AssemblyAccounts (
    aid INT PRIMARY KEY FOREIGN KEY REFERENCES Assemblies(aid),
    actnum INT FOREIGN KEY REFERENCES Accounts(actnum),
    est DATE,
    cost INT,    
);

CREATE TABLE Jobs(
    jnum INT,
    dstart DATE,
    dfin DATE,
    labor_time INT,
    pid INT,
    aid INT,
    dept INT 

    PRIMARY KEY(jnum),
    FOREIGN KEY(pid) REFERENCES Processes (pid),
    FOREIGN KEY(aid) REFERENCES Assemblies (aid),
    FOREIGN KEY (dept) REFERENCES Departments(dnum)
);

CREATE TABLE CutJobs (
    jnum INT,
    mtime INT,
    mat VARCHAR(64),

    PRIMARY KEY(jnum),
    FOREIGN KEY(jnum) REFERENCES Jobs(jnum)
);

CREATE TABLE PaintJobs (
    jnum INT,
    color VARCHAR(32),
    volume INT,

    PRIMARY KEY(jnum),
    FOREIGN KEY(jnum) REFERENCES Jobs (jnum)
);

CREATE TABLE FitJobs (
    jnum INT,

    PRIMARY KEY(jnum),
    FOREIGN KEY(jnum) REFERENCES Jobs (jnum)
);

CREATE TABLE Transactions (
    tnum INT PRIMARY KEY,
    jnum INT FOREIGN KEY REFERENCES Jobs(jnum),
    cost INT
);

CREATE INDEX department ON Jobs(department);
CREATE INDEX assemb ON Jobs(aid);