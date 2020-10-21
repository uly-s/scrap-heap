import React from 'react';

export default class Textarea extends React.Component {

  componentDidMount () {
    if (this.multilineTextarea) {
      this.multilineTextarea.style.height = 'auto';
    }
  }

  changeTextarea = () => {
    this.multilineTextarea.style.height = 'auto';
    this.multilineTextarea.style.height = this.multilineTextarea.scrollHeight + 'px';
  }

  render () {
    return (
      <textarea
        onChange={this.changeTextarea}
        ref={ref => this.multilineTextarea = ref}
      />
    );
  }
}