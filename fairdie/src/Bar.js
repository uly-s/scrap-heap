import React from 'react';




class HeaderBar extends React.Component {

  constructor(props) {
    super(props)


  }

  render() {
    return (
      <div>
        <header className="App-header">
          <img src={logo} className="App-logo" alt="logo" />
          <p>
            Edit <code>src/App.js</code> and save to reload.
          </p>
          <a
            className="App-link"
            href="https://reactjs.org"
            target="_blank"
            rel="noopener noreferrer"
          >
            Learn React
          </a>
      </header>
    </div>);
  }
}

export default HeaderBar;


