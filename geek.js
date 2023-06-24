import React from 'react'

class App extends React.Component {

    state = {
        value: 10
    }

    onValueChange = (event) => {
        this.setState({ value: event.target.value })
    }

    render() {
        return (
            <td>
                <label> Floating Number: </label>
                <input
                    type='number'
                    step="0.1"
                    min='0'
                    max='20'
                    value={this.state.value}
                    onChange={(event) => this.onValueChange(event)}
                />
            </td>
        )
    }

}

export default App;